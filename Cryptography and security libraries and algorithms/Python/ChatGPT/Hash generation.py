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
def generate_hash(password):
    salt = os.urandom(32)
    key = hashlib.pbkdf2_hmac('sha256', password.encode('utf-8'), salt, 100000)
    return salt + key
MyPassword = "123Pass"
MyHash = generate_hash(MyPassword)