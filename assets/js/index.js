$(document).ready(() => {
	$('#login-form').submit(function(e) {
		disableLink(e);
		$.post($(this).attr('action'), $(this).serialize(), result => {
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