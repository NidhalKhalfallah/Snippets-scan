class Family:
    def __init__(self,name,members):
        self.name = name
        self.members = members


class Chat:
    def __init__(self,family,content):
        self.family = family
        self.content = content
    #define a function for a user to read a family chat
    def read(self):
        print(self.family.name + ": " + self.content)