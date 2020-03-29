doc.ready(() => {
	$('[data-script]').each(function() {
		$(this).click(function(e) {
			disableLink(e);
			const url = $(this).attr('href');
			const script = $(this).attr('data-script');
			$.get(url, result => {
				container.loadHTML(result);
				loadScript(script);
			});
		});
	});
});