from fastapi import FastAPI
from pydantic import BaseModel
app = FastAPI()
class LoginRequest(BaseModel):
    username: str
    password: str
#grab the user name and password
@app.post("/login")
async def login(request: LoginRequest):
    if request.username == "test" and request.password == "test":
        return {"token": "fake-super-secret-token"}

    return {"detail":"Invalid username or password"}
