interface Student {
	firstName: string;
	lastName: string;
	age: number;
	location: string;
}

const student1: Student = {
	firstName: "John",
	lastName: "Doe",
	age: 30,
	location: "Los Angeles"
};

const student2: Student = {
	firstName: "Jane",
	lastName: "Doe",
	age: 29,
	location: "Massachusetts"
};

const studentsList: Student[] = [student1, student2];

// Create table
const table = document.createElement('table');
const tableHeader = document.createElement('tr');
const header1 = document.createElement('th');
const header2 = document.createElement('th');

header1.textContent = 'First Name';
header2.textContent = 'Location';

tableHeader.appendChild(header1);
tableHeader.appendChild(header2);
table.appendChild(tableHeader);

studentsList.forEach((student) => {
	const row = document.createElement('tr');
	const firstNameCell = document.createElement('td');
	const locationCell = document.createElement('td');

	firstNameCell.textContent = student.firstName;
	locationCell.textContent = student.location;

	row.appendChild(firstNameCell);
	row.appendChild(locationCell);
	table.appendChild(row);
});

document.body.appendChild(table);
