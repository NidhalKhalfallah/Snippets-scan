class Family:
    def __init__(self,name,members):
        self.name = name
        self.members = members

class Chat:
    def __init__(self,family,content):
        self.family = family
        self.content = content
    #define a function for a user to read a family chat
class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email
        
    def read_chat(self, chat):
        if chat.family.members.count(self.name) > 0:
            print(f"----- {chat.family.name} chat -----")
            for message in chat.content:
                print(f"{message['sender']}: {message['text']}")
        else:
            print("You are not a member of this family chat!")