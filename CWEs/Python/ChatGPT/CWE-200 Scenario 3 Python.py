from fastapi import FastAPI
from pydantic import BaseModel
app = FastAPI()
class LoginRequest(BaseModel):
    username: str
    password: str
#grab the user name and password
@app.post("/login")
async def login(login_request: LoginRequest):
    username = login_request.username
    password = login_request.password
    
    # Your login logic here
    
    return {"message": "Logged in successfully"}