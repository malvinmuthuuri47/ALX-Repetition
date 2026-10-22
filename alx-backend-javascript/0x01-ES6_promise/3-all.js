import { uploadPhoto, createUser } from './utils.js';

export default function handleProfileSignup() {
	Promise.all([uploadPhoto(), createUser()])
	.then(function(res) {
		const [photo, user] = res;
		console.log(photo.body, user.firstName, user.lastName);
	})
	.catch(function(err) {
		console.log('Signup system offline');
	});
}
