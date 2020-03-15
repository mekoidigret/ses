<a class="btn btn-dark" href="add_admin.php">
	Add Admin
</a>
<p id="message-pane"></p>
<script type="text/javascript">
	$(document).ready(() => {
		$('[href="add_admin.php"]').click(function(e) {
			disableLink(e);
			$.get($(this).attr('href'), result => {
				container.loadHTML(result);
			});
		});
	});
</script>
<hr class="my-4" />
<?php if($admins) { ?>
	<table class="table table-sm table-bordered">
		<thead>
			<tr>
				<th>ID</th>
				<th>Username</th>
				<th colspan="2" class="text-center">Action</th>
			</tr>
		</thead>
		<tbody>
			<?php foreach($admins as $admin) { ?>
				<tr>
					<td>
						<?=$admin->id?>
					</td>
					<td>
						<?=htmlentities($admin->username)?>
					</td>
					<td class="text-center">
						<?php include '../templates/modal.admins.inc'; ?>
					</td>
					<td class="text-center">
						<a class="btn btn-danger btn-sm" href="delete_admin.php?id=<?=$admin->id?>">
							Delete
						</a>
					</td>
				</tr>
			<?php } ?>
		</tbody>
	</table>
<?php } else {
	echo 'There are no admins except you.';
} ?>