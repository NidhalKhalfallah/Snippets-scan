from fastapi import FastAPI
from pydantic import BaseModel
app = FastAPI()
class LoginRequest(BaseModel):
    username: str
    password: str
#grab the user name and password
@app.get("/login", response_model=LoginRequest)
def login_get(username: str, password: str):
    return {'username': username, 'password': password}