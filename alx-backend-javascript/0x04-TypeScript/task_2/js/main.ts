interface DirectorInterface {
	workFromHome(): string;
	getCoffeeBreak(): string;
	workDirectorTasks(): string;
};

interface TeacherInterface {
	workFromHome(): string;
	getCoffeeBreak(): string;
	workTeacherTasks(): string;
};

class Director implements DirectorInterface {
	workFromHome(): string {
		return "working from home";
	}

	getCoffeeBreak(): string {
		return "Getting a coffee break";
	}

	workDirectorTasks(): string {
		return "Getting to director tasks";
	}
};

class Teacher implements TeacherInterface {
	workFromHome(): string {
		return "Cannot work from home";
	}

	getCoffeeBreak(): string {
		return "Cannot have a break";
	}

	workTeacherTasks(): string {
		return "Getting to work";
	}
};

function createEmployee(salary: number | string): Director | Teacher {
	if (typeof salary === 'number' && salary < 500) {
		return new Teacher();
	} else {
		return new Director();
	}
};

/* console.log(createEmployee(200)); */

/* console.log(createEmployee(1000)); */

/* console.log(createEmployee('$500')); */

function isDirector(employee: Director | Teacher): employee is Director {
	return (employee as Director).workDirectorTasks !== undefined;
};

function executeWork(employee: Director | Teacher): string {
	if (isDirector(employee)) {
		return employee.workDirectorTasks();
	} else {
		return employee.workTeacherTasks();
	}
};

const employee1 = createEmployee(200);
const employee2 = createEmployee(1000);
const employee3 = createEmployee('$500');

console.log(executeWork(employee1));
console.log(executeWork(employee2));
console.log(executeWork(employee3));

type Subjects = "Math" | "History";

function teachClass(todayClass: Subjects): string {
	if (todayClass === "Math") {
		return "Teaching Math";
	}
	else if (todayClass === "History") {
		return "Teaching History";
	}
	else {
		return "Wrong input";
	}
};

console.log(teachClass('Math'));
console.log(teachClass('History'));
