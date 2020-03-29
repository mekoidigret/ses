$(document).ready(() => {
	$('#register-form').submit(function(e) {
		disableLink(e);
		toggleSpinner(true);
		$.post($(this).attr('action'), $(this).serialize(), result => {
			toggleSpinner(false);
			const data = JSON.parse(result);
			if(data.status) {
				window.location.href = data.location;
			}
			else {
				message(data.message, 'danger');
			}
		});
	});
});