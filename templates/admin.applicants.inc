<div class="col-md-12">

</div>
<p id="message-pane"></p>
<hr class="my-4" />
<?php if($students) { ?>
	<table class="table table-sm table-bordered">
		<thead>
			<tr>
				<th>ID</th>
				<th>Username</th>
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