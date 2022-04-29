(function($) {

  Drupal.behaviors.band_booking_registration = {
    attach: function (context, settings) {

    }
  };

  Drupal.ajax.prototype.commands.afterAjaxCallbackExample = function(ajax, response, status) {
    var $select = $("#register_many_users");
    var $select_options = $select.find('li').not('.ms-select-all, .ms-no-results');
    var $select_option_all = $select.find('li.ms-select-all');

    // If there are artists to hide.
    if(Object.keys(response.artists_to_hide).length) {
      // Hide the 'All option".
      $select_option_all.find('label').hide();

      // Hide options to hide.
      Object.keys(response.artists_to_hide).map(function(artist_id, index) {
        $select_options.find('input[value="' + artist_id + '"]').parents('li').hide();
      });

      // Show options to show.
      Object.keys(response.artists_with_position).map(function(artist_id, index) {
        $select_options.find('input[value="' + artist_id + '"]').parents('li').show();
      });

    }
    // If there are no artist to hide.
    else {
      // Show the "All option".
      $select_option_all.find('label').show();

      // If some options are hidden.
      Object.keys(response.artists_with_position).map(function(artist_id, index) {
        $select_options.find('input[value="' + artist_id + '"]').parents('li').show();
      });
    }
  };

})(jQuery);
