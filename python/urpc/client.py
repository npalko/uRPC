import uRPC_pb2
import zmq


class SingleThreadClient(object):
  def __init__(self, connection = 'tcp://127.0.0.1:5555'):
    self._context = zmq.Context()
    self._socket = self._context.socket(zmq.REQ)
    self._socket.connect(connection)

  def sendRequest(self, service, version, request):

    envelope = uRPC_pb2.RequestEnvelope()
    envelope.service = service
    envelope.version = version
    envelope.request = request.SerializeToString()

    self._socket.send(envelope.SerializeToString())
  def getReply(self):


    envelope = uRPC_pb2.ReplyEnvelope()
    envelope.ParseFromString(self._socket.recv())

    return envelope.reply
