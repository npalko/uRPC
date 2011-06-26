

/*
 
 idea here is to have a std::map (key,function pointer) 
  - specify the kind of key
  - specify function pointer - pointer to base class
 
 
 Factory<std::string,IService> serviceFactory
 
 scoped_ptr<IService> service = serviceFactory.get(key)
 
 serviceFactory.register(NULL, notImplemented)
 
 
 */



namespace urprc {

template < >
class Factory




}