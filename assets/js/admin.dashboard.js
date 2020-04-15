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
		const analytics = $('#analytics');
		const { enrolled, dropped, applicant } = data;
		const chart = new Chart(analytics, {
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
					backgroundColor: 'rgb(200, 150, 90)',
					data: Object.values(enrolled),
				},{
					label: 'Dropped',
					backgroundColor: 'rgb(50, 90, 150)',
					data: Object.values(dropped),
				},/*{
					label: 'Applicants',
					backgroundColor: 'rgb(125, 150, 185)',
					data: Object.values(applicant),
				}*/],
			}
		});
	}, 'json');
});