# Generated by the protocol buffer compiler.  DO NOT EDIT!

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


DESCRIPTOR = descriptor.FileDescriptor(
  name='uRPC.proto',
  package='urpc',
  serialized_pb='\n\nuRPC.proto\x12\x04urpc\x1a\tLog.proto\"<\n\x07Request\x12\x0f\n\x07service\x18\x01 \x01(\t\x12\x0f\n\x07version\x18\x02 \x01(\x05\x12\x0f\n\x07message\x18\x03 \x01(\x0c\"=\n\x08Response\x12\r\n\x05\x65rror\x18\x01 \x01(\x08\x12\x0f\n\x07message\x18\x02 \x01(\x0c\x12\x11\n\x03log\x18\x03 \x03(\x0b\x32\x04.Log\"m\n\nServerList\x12\'\n\x06server\x18\x01 \x03(\x0b\x32\x17.urpc.ServerList.Server\x1a\x36\n\x06Server\x12\x0c\n\x04name\x18\x01 \x01(\t\x12\x0c\n\x04port\x18\x02 \x01(\x05\x12\x10\n\x08priority\x18\x03 \x01(\x05')




_REQUEST = descriptor.Descriptor(
  name='Request',
  full_name='urpc.Request',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='service', full_name='urpc.Request.service', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='version', full_name='urpc.Request.version', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='message', full_name='urpc.Request.message', index=2,
      number=3, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value="",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=31,
  serialized_end=91,
)


_RESPONSE = descriptor.Descriptor(
  name='Response',
  full_name='urpc.Response',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='error', full_name='urpc.Response.error', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='message', full_name='urpc.Response.message', index=1,
      number=2, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value="",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='log', full_name='urpc.Response.log', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=93,
  serialized_end=154,
)


_SERVERLIST_SERVER = descriptor.Descriptor(
  name='Server',
  full_name='urpc.ServerList.Server',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='name', full_name='urpc.ServerList.Server.name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='port', full_name='urpc.ServerList.Server.port', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='priority', full_name='urpc.ServerList.Server.priority', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=211,
  serialized_end=265,
)

_SERVERLIST = descriptor.Descriptor(
  name='ServerList',
  full_name='urpc.ServerList',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='server', full_name='urpc.ServerList.server', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[_SERVERLIST_SERVER, ],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=156,
  serialized_end=265,
)

import Log_pb2

_RESPONSE.fields_by_name['log'].message_type = Log_pb2._LOG
_SERVERLIST_SERVER.containing_type = _SERVERLIST;
_SERVERLIST.fields_by_name['server'].message_type = _SERVERLIST_SERVER

class Request(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _REQUEST
  
  # @@protoc_insertion_point(class_scope:urpc.Request)

class Response(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _RESPONSE
  
  # @@protoc_insertion_point(class_scope:urpc.Response)

class ServerList(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  
  class Server(message.Message):
    __metaclass__ = reflection.GeneratedProtocolMessageType
    DESCRIPTOR = _SERVERLIST_SERVER
    
    # @@protoc_insertion_point(class_scope:urpc.ServerList.Server)
  DESCRIPTOR = _SERVERLIST
  
  # @@protoc_insertion_point(class_scope:urpc.ServerList)

# @@protoc_insertion_point(module_scope)
