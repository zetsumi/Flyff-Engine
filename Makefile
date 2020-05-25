CC = g++
RM = rm -rf
LIB_FN = libflyffnetwork.so 
LIB_FR = libflyffressource.so 

OBJS_TFN = $(SOURCE:.cpp:.o)

###### FLAGS CPP ######
# CXXFLAGS	+= -W -Wall -Wextra
CXXFLAGS	+= -pedantic -ansi -pipe
CXXFLAGS	+= -O2
ifeq ($(WO_DEBUG), 1)
CXXFLAGS	+= -g3
else
CXXFLAGS	+= -g3 ## TODO : WO_DEBUG
endif
ifeq ($(WO_COPLIEN), 1)
CXXFLAGS	+= -Weffc++
endif
CXXFLAGS	+= -fPIC
CXXFLAGS	+= -std=gnu++1z

###### FLAGS INCLUDE SOURCE ######
CXXFLAGS	+= -I ./source/
CXXFLAGS	+= -I ./source/handler/io/network/
CXXFLAGS	+= -I ./source/handler/io/emit/
CXXFLAGS	+= -I ./source/handler/io/message/
CXXFLAGS	+= -I ./source/handler/cache/
CXXFLAGS	+= -I ./source/handler/cache/packets_snap
CXXFLAGS	+= -I ./source/handler/cache/packets_type/
CXXFLAGS	+= -I ./source/handler/login/
CXXFLAGS	+= -I ./source/util/

###### PATH SOURCE ######
PION = source/io/network/
PIONE = $(PION)emit/
PIONM = $(PION)message/
PHAND = source/handler/
PHANDCC = $(PHAND)cache/
PHANDCT = $(PHAND)certifier/
PHANDL = $(PHAND)login/

###### SOURCE ######
SOURCE_IO_NETWORK = $(PION)network.cpp \
	$(PION)socket_client.cpp

SOURCE_IO_NETWORK_EMIT = $(PIONE)packet_builder.cpp \
	$(PIONE)transaction.cpp \
	$(PIONE)transaction_client.cpp \
	$(PIONE)transaction_emit.cpp

SOURCE_IO_NETWORK_MESSAGE = $(PIONM)handler_message.cpp \
	$(PIONM)handler_message_emit.cpp \
	$(PIONM)handler_message_recv.cpp

SOURCE_HANDLER_LOGIN = $(PHANDL)handler_login.cpp \
	$(PHANDL)handler_login_recv.cpp \
	$(PHANDL)handler_login_emit.cpp \

SOURCE_HANDLER_CERTIFIER = $(PHANDCT)handler_certifier.cpp \
	$(PHANDCT)handler_certifier_recv.cpp \
	$(PHANDCT)handler_certifier_emiter.cpp \

SOURCE_HANDLER_CACHE = $(PHANDCC)handler_cache.cpp \
	$(PHANDCC)handler_cache_recv.cpp \
	$(PHANDCC)handler_cache_recv_snapshot.cpp \
	$(PHANDCC)handler_cache_emit.cpp


SOURCE_FN = $(SOURCE_IO_NETWORK) \
	$(SOURCE_IO_NETWORK_MESSAGE) \
	$(SOURCE_IO_NETWORK_EMIT) \
	$(SOURCE_HANDLER_LOGIN) \
	$(SOURCE_HANDLER_CERTIFIER) \
	$(SOURCE_HANDLER_CACHE) \

###### FICHIER COMPILER ######
OBJS_FN = $(SOURCE_FN:.cpp=.o)

###### RULES ######
all: libflyffnetwork

libflyffnetwork: $(LIB_FN)
$(LIB_FN): $(OBJS_FN)
	$(CC) -shared -o $(LIB_FN) $(OBJS_FN)

clean:
	$(RM) $(LIB_FN)

fclean: clean
	$(RM) $(OBJS_FN)

re: fclean all

.PHONY: all clean fclean re
