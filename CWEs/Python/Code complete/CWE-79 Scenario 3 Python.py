from fastapi import FastAPI
from fastapi import HTTPException
import bleach
import os

Mypassword = os.getenv("PASSWORD")
app = FastAPI()
@app.get("/test/password")
async def test_password(request):
    res= request.query_params.get("password")
    #Verify that the password is correct and send the value of the password back to the user
    if res == Mypassword:
        return {"Password":res}

    #If the password is incorrect, throw an error and send back a message
    else: 
        raise HTTPException(status_code=400, detail="Incorrect Password")

    