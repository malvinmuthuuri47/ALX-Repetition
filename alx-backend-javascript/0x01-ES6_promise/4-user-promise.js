export default function signUpUser(firstName, lastName) {
	return new Promise(function(resolve) {
		resolve({
			firstName: firstName,
			lastName: lastName
		});
	});
}
