from fastapi import FastAPI
from pydantic import BaseModel
app = FastAPI()
class LoginRequest(BaseModel):
    username: str
    password: str
#grab the user name and password
@app.post("/login")
def login(request: LoginRequest):
    return request