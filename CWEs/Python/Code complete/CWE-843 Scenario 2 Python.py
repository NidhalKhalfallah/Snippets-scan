from fastapi import FastAPI
from fastapi import HTTPException

app = FastAPI()

bad_characters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|']

@app.get("/test/document")
async def test_document(document: str):
#Send the document to the server
    for character in bad_characters:
        if character in document:
            raise HTTPException(status_code=400, detail="Bad Request")

    return {"document": document}
