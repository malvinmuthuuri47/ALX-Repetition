/// <reference path="./interface.ts" />
/// <reference path="./crud.d.ts" />

import { RowID, RowElement } from "./interface";
import * as CRUD from "./crud";

const row: RowElement = {
	firstName: "Guillaume",
	lastName: "Salva"
};

const newRowID: RowID = CRUD.insertRow(row);
console.log(`Inserted row:`, newRowID);

const updateRow: RowElement = {
	...row,
	age: 23
};

const newUpdateRow = CRUD.updateRow(newRowID, updateRow);
console.log('Updated row', newUpdateRow);

console.log('Delete row', CRUD.deleteRow(747));
