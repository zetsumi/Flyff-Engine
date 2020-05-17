#include <framework_fengine.h>
#include <pch_fnetwork.h>



//#define	PACKETTYPE_SRVR_LIST	(DWORD)0x000000fd
//#define	PACKETTYPE_ERROR	(DWORD)0x000000fe
//#define	PACKETTYPE_ERROR_STRING	(DWORD)0x70000003
#define	PACKETTYPE_KEEP_ALIVE	(DWORD)0x00000018
#define	PACKETTYPE_PING		(DWORD)0x00000014
#define	PACKETTYPE_CERTIFY	(DWORD)0x000000fc

unsigned int session_id = 0;

static void	send_certify(SOCKET id)
{
	fe::PacketBuilder pb;
	pb.write<unsigned int>(PACKETTYPE_CERTIFY);
	pb.writeString("20100412");
	pb.writeString("test10");
	pb.writeString("4d1677b3d55fd9c68e6baa7b1bd638d0");
	::send(id, (char*)pb.getData(false), pb.getSize(), 0);
}

static void	my_callback(SOCKET id, fe::PacketStructure* ps)
{
	fe::PacketBuilder pb;
	pb.setPacket(ps);

	const unsigned char* data = pb.getData(false);
	unsigned int size = pb.getSize();

	FE_CONSOLELOG("size:<%u>", size);
	for (unsigned int i = 0; i < size; ++i)
		FE_CONSOLELOG("%02x", data[i]);

	for (unsigned int i = 0; i < 5; ++i)
		pb.read<char>();

	FE_CONSOLELOG("***");
	unsigned int packettype = pb.read<unsigned int>();
	FE_CONSOLELOG("packettype<%u>",packettype);
	FE_CONSOLELOG("***");

	if (packettype == 0)
	{
		session_id = pb.read<unsigned int>();
	}

}

int main()
{
	FE_CONSOLELOG("running client test");

	fe::Network network;
	fe::SocketClient socket;
	fe::Transaction trans;

	network.setIP("127.0.0.1");
	network.setPort(23000);
	if (network.isValid() == false)
		return 1;
	if (socket.connect(network) == false)
		return 2;
	trans.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);
	if (trans.setSocket(&socket) == false)
		return 3;

	if (trans.run(my_callback) == false)
		return 4;
	trans.wait();

	// reco
	if (socket.connect(network) == false)
		return 2;
	trans.run(my_callback);
	trans.wait();

	return 0;
}