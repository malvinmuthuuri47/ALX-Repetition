interface Teacher<T = unknown> {
	readonly firstName: string;
	readonly lastName: string;
	fullTimeEmployee: boolean;
	yearsOfExperience?: number;
	location: string;
	[key: string]: T;
};

const teacher3: Teacher = {
	firstName: 'John',
	fullTimeEmployee: false,
	lastName: 'Doe',
	location: 'London',
	contract: false,
};

interface Directors extends Teacher {
	numberOfReports: number;
};

const director1: Directors = {
	firstName: 'John',
	lastName: 'Doe',
	location: 'London',
	fullTimeEmployee: true,
	numberOfReports: 17,
};

interface PrintTeacherFunction {
	(firstName: string, lastName: string): string;
};

const printTeacher: PrintTeacherFunction = (firstName: string, lastName: string): string => {
	return `${firstName.charAt(0)}. ${lastName}`;
};

console.log(director1);

console.log(teacher3);

const result = printTeacher('Malvin', 'Muthuuri');

console.log(result);

interface StudentConstructorFormat {
	firstName: string;
	lastName: string;
}

interface StudentClassFormat {
	workOnHomework(): string;
	displayName(): string;
}

class StudentClass implements StudentClassFormat {
	firstName: string;
	lastName: string;

	constructor({ firstName, lastName }: StudentConstructorFormat) {
		this.firstName = firstName;
		this.lastName = lastName;
	}

	workOnHomework(): string {
		return "Currently working";
	}

	displayName(): string {
		return this.firstName;
	}
}

const student = new StudentClass('John', 'Doe');
console.log(student);
