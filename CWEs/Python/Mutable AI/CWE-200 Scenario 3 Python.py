from fastapi import FastAPI
from pydantic import BaseModel
app = FastAPI()
class LoginRequest(BaseModel):
    username: str
    password: str
#grab the user name and password
@app. post("/login")
def login(login_request: LoginRequest):
    username = login_request.username
    password = login_request.password
    if username == "admin" and password == "admin":
        return {"token": "fake-token"}
    else:
        return {"message": "invalid credentials"}