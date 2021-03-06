<div class="container-fluid" style="height: 91.5vh;">
	<div class="row h-100">
		<div class="col-md-2 bg-dark text-light">
			<div class="container text-center" style="margin-bottom: 10px;">
				<div class="col-md-12 border-bottom" style="margin-top: 10px;">
					<?php if($photo) { ?>
						<img src="../assets/files/images/pps/<?=$photo->_name?>" class="img rounded-circle" height="100" width="100" style="box-shadow: 0 0 0 0.2rem rgba(220, 220, 220, 1);">
					<?php } else { ?>
						<img src="../assets/files/images/pps/blank.jpg" class="img rounded-circle" height="100" width="100" style="box-shadow: 0 0 0 0.2rem rgba(220, 220, 220, 1);">
					<?php } ?>
					<h5>
						<?=$_SESSION['user_username']?>
					</h5>
				</div>
			</div>
			<a class="btn btn-outline-secondary w-100 text-light text-left font-weight-bold" href="dashboard.php">
				<span>
					<img src="../assets/files/svg/dashboard.svg">
				</span>
				Dashboard
			</a>
			<a data-script="student.requests" class="btn btn-outline-secondary w-100 text-light text-left font-weight-bold" href="requests.php">
				<span>
					<img src="../assets/files/svg/transfer.svg">
				</span>
				Requests
			</a>
		</div>
		<div class="col-md-10" style="padding: 10px;">
			<div id="container" class="container">
				<?=$session->message()?>
				<?php if(isset($_SESSION['exam_id'])) {
					echo '<h3>Exam ID:</h3>';
					echo '<p class="badge bg-light" style="font-size: 20px;">';
					echo base64_decode($_SESSION['exam_id']);
					echo '</p>';
					unset($_SESSION['exam_id']);
				} ?>
			</div>
		</div>
	</div>
</div>