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

	$.get('api.php', data => {
		const analytics_enrollment = $('#analytics-enrollment');
		const { enrolled, dropped } = data;
		const enrollment_chart = new Chart(analytics_enrollment, {
			type: 'bar',
			options: {
				title: {
					display: true,
					fontSize: 26,
					text: 'Rate of Enrollment'
				}
			},
			data: {
				labels: Object.keys(data.enrolled),
				datasets:[{
					label: 'Enrolled',
					backgroundColor: 'rgb(100, 150, 230)',
					data: Object.values(enrolled),
				},{
					label: 'Dropped',
					backgroundColor: 'rgb(230, 100, 100)',
					data: Object.values(dropped),
				},],
			}
		});
	}, 'json');
});