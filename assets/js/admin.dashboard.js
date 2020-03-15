doc.ready(() => {
	$('[data-script]').each(function() {
		$(this).click(function(e) {
			disableLink(e);
			const script_name = $(this).attr('data-script');
			const url = $(this).attr('href');
			$.get(url, result => {
				container.loadHTML(result);
				loadScript(script_name);
			});
		});
	});
});