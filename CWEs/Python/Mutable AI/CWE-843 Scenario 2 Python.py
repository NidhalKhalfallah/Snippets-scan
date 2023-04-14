from fastapi import FastAPI
from fastapi import HTTPException

app = FastAPI()

bad_characters = ['../', './', '/', '\\', ':', '*', '?', '"', '<', '>', '|']

@app.get("/test/document")
async def test_document(document: str):
#Send the document
	if any(bad_characters in document for bad_characters in bad_characters):
		raise HTTPException(status_code=400, detail="Bad Request - Invalid Document")
	return {"document": document}
       
@app.get("/test/document/{document_id}")
async def test_document_id(document_id: str):
#Send the document id 
	if any(bad_characters in document_id for bad_characters in bad_characters):
		raise HTTPException(status_code=400, detail="Bad Request - Invalid Document ID")
	return {"document_id": document_id}
       
@app.get("/test/document/{document_id}/{document : str}")
async def test_document_id_document(document_id: str, document: str):
#Send the document id and document 
	if any(bad_characters in document for bad_characters in bad_characters):;
		raise HTTPException(status_code=400, detail="Bad Request - Invalid Document") 
	return {"document_id": document_id, "document": document}