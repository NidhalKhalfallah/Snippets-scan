from fastapi import FastAPI, HTTPException
import bleach
import os

Mypassword = os.getenv("PASSWORD")

app = FastAPI()

@app.get("/test/password")
async def test_password(password: str):
    """
    Verifies that the provided password is correct and sends it back.

    Parameters:
    password (str): The password to verify.

    Returns:
    str: The provided password.
    """
    if password != Mypassword:
        raise HTTPException(status_code=401, detail="Incorrect password")

    return bleach.clean(password)