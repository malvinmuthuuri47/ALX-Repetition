export default function getFullResponseFromAPI(success) {
	if (success === true) {
		return new Promise(function(resolve) {
			resolve({'status': 200, 'body': 'Success'});
		})
	} else {
		return new Promise(function(resolve, reject) {
			reject(new Error("The fake API is not working currently."));
		});
	};
}
