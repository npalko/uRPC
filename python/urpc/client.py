import uRPC_pb2
import zmq


class SingleThreadClient(object):
  def __init__(self, connection = 'tcp://127.0.0.1:5555'):
    self._context = zmq.Context()
    self._socket = self._context.socket(zmq.REQ)
    self._socket.connect(connection)

  def sendRequest(self, service, version, request):

    requestEnvelope = uRPC_pb2.RequestEnvelope()
    requestEnvelope.service = service
    requestEnvelope.version = version
    requestEnvelope.request = request.SerializeToString()

    self._socket.send(requestEnvelope.SerializeToString())
  def getReply(self):


    replyEnvelope = uRPC_pb2.ReplyEnvelope()
    replyEnvelope.ParseFromString(self._socket.recv())

    return replyEnvelope.reply
