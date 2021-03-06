#using <system.dll>
#using <system.runtime.remoting.dll>
#using <Service.dll>

using namespace System;
using namespace System::Runtime::Remoting;
using namespace System::Runtime::Remoting::Channels;
using namespace System::Runtime::Remoting::Channels::Tcp;
using namespace System::Runtime::Remoting::Channels::Http;
using namespace System::Runtime::Remoting::Lifetime;
using namespace SampleNamespace;

// This assembly contains a remote service and its server host wrapped together.
int main()
{
   
   // The following sample uses an HttpChannel constructor
   // to create a new HttpChannel that will listen on port 9000.
   // System::Runtime::Remoting::Channels.Http::HttpChannel.HttpChannel(int)
   // System::Runtime::Remoting::Channels.Http::HttpChannel
   // <Snippet1>
   HttpChannel^ channel = gcnew HttpChannel( 9000 );
   ChannelServices::RegisterChannel( channel, false );
   RemotingConfiguration::RegisterWellKnownServiceType( SampleNamespace::SampleService::typeid, "MySampleService/SampleService::soap", WellKnownObjectMode::Singleton );
   Console::WriteLine( "** Press enter to end the server process. **" );
   Console::ReadLine();
   // </Snippet1>

   return 0;
}