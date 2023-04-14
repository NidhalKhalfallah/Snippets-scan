from fastapi import FastAPI
from fastapi import HTTPException

app = FastAPI()

bad_characters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|']

@app.get("/test/document")
async def test_document(document: str):
    #Send the document
  return document