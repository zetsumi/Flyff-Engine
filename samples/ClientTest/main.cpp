#include <framework_fengine.h>
#include <pch_fnetwork.h>


#define	PACKETTYPE_SRVR_LIST	(DWORD)0x000000fd
#define	PACKETTYPE_ERROR	(DWORD)0x000000fe
#define	PACKETTYPE_ERROR_STRING	(DWORD)0x70000003
#define	PACKETTYPE_KEEP_ALIVE	(DWORD)0x00000018
#define	PACKETTYPE_PING		(DWORD)0x00000014
#define	PACKETTYPE_CERTIFY	(DWORD)0x000000fc
#define	PACKETTYPE_WELCOME	(DWORD)0x00000000

fe::Network			network{};
fe::SocketClient	_socket{};
fe::Transaction		trans{};

bool	testCo = false;
unsigned int session_id = 0;



static void	send_certify(SOCKET id)
{
	//FE_CREATE_PACKET(PACKETTYPE_CERTIFY, session_id)
	fe::PacketBuilder pb;

	pb.write<unsigned int>(PACKETTYPE_CERTIFY);
	pb.writeString("20100412");
	pb.writeString("test10");
	pb.writeString("4d1677b3d55fd9c68e6baa7b1bd638d0");

	pb.debug();
	pb.setHeader(session_id);
	pb.debug();

	auto buffer = pb.getData();
	auto length = pb.getSize();
	::send(id, (char*)buffer, length, 0);
}

static void	my_callback(SOCKET id, fe::PacketStructure* ps)
{
	fe::PacketBuilder pb;
	pb.setPacket(ps);


	FE_CONSOLELOG("***");
	unsigned char	headmark = pb.read<unsigned char>();
	unsigned int	length = pb.read<unsigned int>();
	unsigned int	packettype = pb.read<unsigned int>();
	FE_CONSOLELOG("headmark<%c><%02x> length<%u> packettype<%u>", headmark, headmark, length, packettype);
	FE_CONSOLELOG("***");

	if (packettype == PACKETTYPE_WELCOME)
	{
		session_id = pb.read<unsigned int>();
		testCo = true;
		send_certify(id);
	}

}


static bool	test_connection_certifier(void)
{
	trans.setSocket(&_socket);
	trans.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);

	if (_socket.connect(network) == false)
		return false;
	if (trans.run(my_callback) == false)
		return false;
	trans.wait(false);
	while (testCo == false)
		;
	_socket.shutdown();
	return true;
}


static bool	login_certifier(void)
{
	trans.setSocket(&_socket);
	trans.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);

	if (_socket.connect(network) == false)
		return false;
	trans.run(my_callback);
	trans.wait();
	return true;
}

int main()
{
	FE_CONSOLELOG("running client test");

	network.setIP("127.0.0.1");
	network.setPort(23000);
	if (network.isValid() == false)
		return false;

	//if (test_connection_certifier() == false)
	//	return 1;

	if (login_certifier() == false)
		return 2;

	return 0;
}