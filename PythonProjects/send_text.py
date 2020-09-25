#   SMS messages sent via Twilio
#
#   Written for Python 2.7
#
#   Udacity's Programming Foundations with Python

from twilio.rest import Client

account_sid = "ACd6fe005bf289bd7af6c58cd873485210"
auth_token  = "b3b28edba986edadcf838d7df90d794a"

client = Client(account_sid, auth_token)

message = client.messages.create(
    to="+16506667263", 
    from_="+16508221096",
    body="Hi self!")

print(message.sid)
