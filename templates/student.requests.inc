<a style="margin: 10px 10px 10px 0;" class="btn btn-dark" href="request.php">
	Request Enrollment
</a>
<hr class="my-4" />
<div id="message-pane"></div>
<?php if($requests) { ?>
	<table class="table table-sm">
		<thead>
			<tr>
				<th>ID</th>
				<th>Date</th>
				<th>Passed</th>
			</tr>
		</thead>
		<tbody>
			<?php foreach($requests as $request) { ?>
				<tr>
					<td><?=htmlentities($request->id)?></td>
					<td>
						<?php
							$date = new DateTime($request->date);
							$date_formatted = $date->format('F d, Y');
							echo $date_formatted;
						?>
					</td>
					<td>
						<?php
						echo $request->passed ? 'Yes' : 'No';
						?>
					</td>
				</tr>
				<?php
					if($request->passed) {
						$request_date = new DateTime($date->format('Y'));
						$current_date = new DateTime(date('Y'));
						if($request_date == $current_date) {
							echo '<script>
								message(\'Congratulations! You have passed the exam. Please go to the registrar to enroll and make sure to keep your Exam ID.\', \'success\', 100000000);
							</script>';
						}
					}
				?>
			<?php } ?>
		</tbody>
	</table>
	<script type="text/javascript">
		if($(window).width() < 400) {
			$('table[class="table table-sm"]').addClass('table-responsive');
		}
		else {
			$('table[class="table table-sm"]').removeClass('table-responsive');
		}
	</script>
<?php } else {
	echo 'You have no requests.';
} ?>