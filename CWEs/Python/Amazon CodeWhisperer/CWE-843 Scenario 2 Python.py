from fastapi import FastAPI
from fastapi import HTTPException

app = FastAPI()

bad_characters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|']

@app.get("/test/document")
async def test_document(document: str):
    #Send the document to the server
    for char in bad_characters:
    for bad_character in bad_characters:
        if char in document:
            raise HTTPException(status_code=400, detail="Bad characters in document")
    return {"document": document}