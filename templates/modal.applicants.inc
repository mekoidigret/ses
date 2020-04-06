<button type="button" class="btn btn-info btn-sm" data-toggle="modal" data-target="#view-student<?=htmlentities($student->id)?>">
	View
</button>
<div class="modal fade" id="view-student<?=htmlentities($student->id)?>" tabindex="-1" role="dialog" aria-labelledby="view-student-title<?=htmlentities($student->id)?>" aria-hidden="true">
	<div class="modal-dialog modal-lg" role="document">
		<div class="modal-content">
			<div class="modal-header">
				<h5 class="modal-title" id="view-student-title<?=htmlentities($student->id)?>">View Student: <?=htmlentities($student->username)?></h5>
				<button type="button" class="close" data-dismiss="modal" aria-label="Close">
					<span aria-hidden="true">&times;</span>
				</button>
			</div>
			<div class="modal-body text-left">
				<?php
					$detail = Detail::findBy('user_id', $student->id);
					$address = Address::findBy('user_id', $student->id);
					$requests = Request::findAllBySQL('SELECT * FROM '.Request::TABLE_NAME.' WHERE user_id = '.$student->id.' ORDER BY date DESC');
				?>
				<h3>Details</h3>
			<?php if($detail) { ?>
				<div class="container">
					<table class="table text-center">
						<thead>
							<tr>
								<th>Name</th>
								<th>Age</th>
								<th>Gender</th>
							</tr>
						</thead>
						<tbody>
							<tr>
								<td>
									<?=$detail->getName()?>
								</td>
								<td>
									<?=$detail->age?>
								</td>
								<td>
									<?=$detail->gender?>
								</td>
							</tr>
						</tbody>
					</table>
				</div>
			<?php } else {
			  echo htmlentities($student->username).' has not added any details.';
			} ?>
			<h5>Address</h5>
			<?php if($address) { ?>
				<div class="container">
					<?=$address?>
				</div>
			<?php } else {
			  echo htmlentities($student->username).' has not added an address.';
			} ?>
			<h5>Requests</h5>
			<?php if($requests) { ?>
				<div class="container">
					<table class="table table-sm">
						<thead>
							<tr>
								<th>Date</th>
								<th>Exam ID</th>
								<th>Passed</th>
								<th>Actions</th>
							</tr>
						</thead>
						<tbody>
							<?php foreach($requests as $request) { ?>
								<tr>
									<td>
										<?php
											$date = new DateTime($request->date);
											$date_formatted = $date->format('F d, Y');
											echo $date_formatted;
										?>
									</td>
									<td><?=htmlentities($request->id)?></td>
									<td>
										<?php
										echo $request->passed ? 'Yes' : 'No';
										?>
									</td>
									<td>
										<?php if($request->passed) { ?>
											<a class="btn btn-warning text-light btn-sm disabled" href="toggle.php?id=<?=urlencode(base64_encode($request->id))?>">
												Already Passed
											</a>
										<?php } else { ?>
											<a class="btn btn-danger btn-sm" href="toggle.php?id=<?=urlencode(base64_encode($request->id))?>">
												Toggle Passed
											</a>
										<?php } ?>
									</td>
								</tr>
							<?php } ?>
						</tbody>
					</table>
				</div>
			<?php } ?>
			</div>
			<div class="modal-footer">
				<button type="button" class="btn btn-secondary btn-sm" data-dismiss="modal">Close</button>
			</div>
		</div>
	</div>
</div>