import uRPC_pb2
import zmq


class SingleThreadClient(object):
  def __init__(self, connection = urpc.dns.getConnection()):
    pass
  def sendRequest(self, service, version, request, moreToFollow = false):
    pass
  def getResponse(self):
    pass
    