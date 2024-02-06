// ***************************************************************************
// TITLE
//
// PROJECT
//     1
// ***************************************************************************

#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/DialogSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/SocketAddress.h"

// ---------------------------------------------------------------------------
// ------------------------------- DEFINITIONS -------------------------------
// -----|-------------------|-------------------------------------------------

#define MAX_SYMB_IN_STRING	255
#define PORT_NUMBER 		28888

// ---------------------------------------------------------------------------
// ---------------------------------- DATA -----------------------------------
// -----|-------------------|-------------------------------------------------

const char * welcomeStr = "Welcome to POCO TCP server. Enter you string:\r\n";

// ---------------------------------------------------------------------------
// -------------------------------- FUNCTIONS --------------------------------
// -----------------|---------------------------(|------------------|---------


int main(int argc, char** argv)
{
	char 	inBuff [ MAX_SYMB_IN_STRING ];

	Poco::Net::ServerSocket srv(PORT_NUMBER); 

	for (;;)
	{
		Poco::Net::DialogSocket ss = srv.acceptConnection();
		ss.sendBytes(welcomeStr, strlen(welcomeStr), 0);

		int 	rd;
		while ((rd = ss.receiveBytes(inBuff, sizeof(inBuff), 0)) > 0)
		{
			std::reverse(inBuff, inBuff + rd);
			inBuff[ rd++ ] = '\n';
			ss.sendBytes(inBuff, rd, 0);
		}
	}
	return 0;
}