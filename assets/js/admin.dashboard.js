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
		const enrolled = data.enrolled;
		const dropped = data.dropped;
		const applicant = data.applicant;
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
				labels: ['2015', '2016', '2017', '2018', '2019', '2020'],
				datasets:[{
					label: 'Enrolled',
					backgroundColor: 'rgb(200, 150, 90)',
					data: [
						enrolled['2015'],
						enrolled['2016'],
						enrolled['2017'],
						enrolled['2018'],
						enrolled['2019'],
						enrolled['2020']
					],
				},{
					label: 'Dropped',
					backgroundColor: 'rgb(50, 90, 150)',
					data: [
						dropped['2015'],
						dropped['2016'],
						dropped['2017'],
						dropped['2018'],
						dropped['2019'],
						dropped['2020']
					],
				},{
					label: 'Applicants',
					backgroundColor: 'rgb(125, 150, 185)',
					data: [
						applicant['2015'],
						applicant['2016'],
						applicant['2017'],
						applicant['2018'],
						applicant['2019'],
						applicant['2020']
					],
				}],
			}
		});
	}, 'json');
});