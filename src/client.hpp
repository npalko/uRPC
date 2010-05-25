#ifndef URPC_CLIENT_HPP
#define URPC_CLIENT_HPP


  /*
  
  allow for multi-part requests
  sendRequest()
  sendLastRequest()
  
  getResponse()
  
  
  mylib::request myrequest;
  myrequest.set_();
  myreuqest.set_();
  
  uprc::Client client;
  client.connect();
  mylib::response response = client.request(version, service, myrequest);
  
  // call close() in ~client

  
  
  
  */

namespace urpc
{
  class Client
  {
  public:
    Client ();
    int connect ();
    request ();
    int close ();
    ~Client ();
  private:
  }




}
#endif // URPC_HPP