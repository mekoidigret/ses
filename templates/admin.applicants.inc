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
		<thead>
			<tr>
				<th>ID</th>
				<th>Username</th>
				<th>Status</th>
				<th class="text-center">Actions</th>
			</tr>
		</thead>
		<tbody>
			<?php foreach($students as $student) { ?>
				<tr>
					<td>
						<?=$student->id?>
					</td>
					<td>
						<?=htmlentities($student->username)?>
					</td>
					<td>
						<?=htmlentities($student->status)?>
					</td>
					<td class="text-center">
						<?php include '../templates/modal.applicants.inc'; ?>
					</td>
				</tr>
			<?php } ?>
		</tbody>
	</table>
<?php } else {
	echo 'There are no students/applicants.';
} ?>