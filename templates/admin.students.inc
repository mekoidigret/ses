<div class="col-md-12">
	<a href="add_student.php" class="btn btn-dark disabled">
		Add Student
	</a>
</div>
<script defer="" type="text/javascript">
	setTimeout(() => {
		$(document).ready(() => {
			$('a[href="add_student.php"]').removeClass('disabled');
			$(document).on('click', 'a[href="add_student.php"]', function(e) {
				disableLink(e);
				$.get($(this).attr('href'), html => {
					container.loadHTML(html);
				});
			});
		});
	}, 1000);
</script>
<p id="message-pane"></p>
<hr class="my-4" />
<?php if($students) { ?>
	<table class="table table-sm table-bordered">
		<thead class="thead-dark">
			<tr>
				<th>Full Name</th>
				<th>Gender</th>
				<th>School</th>
				<th>Year</th>
				<th>Status</th>
			</tr>
		</thead>
		<tbody>
			<?php foreach($students as $student) { ?>
				<tr>
					<td>
						<?=$count++.') '.htmlentities($student->full_name)?>
					</td>
					<td>
						<?=htmlentities($student->gender)?>
					</td>
					<td>
						<?=htmlentities($student->school)?>
					</td>
					<td>
						<?=htmlentities($student->year)?>
					</td>
					<td>
						<?=htmlentities($student->status)?>
					</td>
				</tr>
			<?php } ?>
		</tbody>
	</table>
	<?=$pagination?>
<?php } else {
	echo 'There are no students/applicants.';
} ?>