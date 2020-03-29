$(document).ready(() => {
	$('[data-dismiss="toast"]').on('click', function(e) {
		e.preventDefault();
		$($(this).attr('data-target')).toast('hide');
		e.stopImmediatePropagation();
	});
});

function hideToast() {
	$('#message-toast').toast('hide');
}