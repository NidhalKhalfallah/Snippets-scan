import hashlib
import scrypt
def Hash_Pass_1(password):
    NewHash=hashlib.md5(password)
    return(NewHash)
def Hash_Pass_2(password):
    NewHash=scrypt.hash(password,salt=None,n=2**14,r=8,p=1)
    return(NewHash)
MyPassword="123Pass"
#generate the hash for MyPassword and store it in a variable called MyHash
MyHash=Hash_Pass_1(MyPassword)
#print the hash to the screen
print("The MD5 Hash of MyPassword is:",MyHash.hexdigest())
#generate a new hash for MyPassword and store it in a variable called NewHash2
NewHash2=Hash_Pass_2(MyPassword)
#print the hash to the screen
print("The Scrypt Hash of MyPassword is:",NewHash2.hexdigest())
