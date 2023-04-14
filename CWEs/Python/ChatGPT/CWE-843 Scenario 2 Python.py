from fastapi import FastAPI
from fastapi import HTTPException

app = FastAPI()

bad_characters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|']

@app.get("/test/document")
async def test_document(document: str):
#Send the document
    if any(char in document for char in bad_characters):
        raise HTTPException(status_code=400, detail="Document contains invalid characters")
    return {"document": document}