<button type="button" class="btn btn-info btn-sm" data-toggle="modal" data-target="#view-admin<?=htmlentities($admin->id)?>">
	View
</button>
<div class="modal fade" id="view-admin<?=htmlentities($admin->id)?>" tabindex="-1" role="dialog" aria-labelledby="view-admin-title<?=htmlentities($admin->id)?>" aria-hidden="true">
  	<div class="modal-dialog modal-lg" role="document">
    	<div class="modal-content">
      		<div class="modal-header">
        		<h5 class="modal-title" id="view-admin-title<?=htmlentities($admin->id)?>">View Admin</h5>
        		<button type="button" class="close" data-dismiss="modal" aria-label="Close">
          			<span aria-hidden="true">&times;</span>
        		</button>
      		</div>
      		<div class="modal-body text-left">
      			<?php
      				$detail = Detail::findBy('user_id', $admin->id);
      				$address = Address::findBy('user_id', $admin->id);
      			?>
      			<h3>Details</h3>
            <?php if($detail) { ?>
            <?php } else {
              echo htmlentities($admin->username).' has not added any details.';
            } ?>
            <h3>Address</h3>
            <?php if($address) { ?>
            <?php } else {
              echo htmlentities($admin->username).' has not added an address.';
            } ?>
      		</div>
      		<div class="modal-footer">
        		<button type="button" class="btn btn-secondary btn-sm" data-dismiss="modal">Close</button>
      		</div>
    	</div>
	</div>
</div>