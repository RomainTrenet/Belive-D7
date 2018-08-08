(function($) {

  Drupal.behaviors.band_booking_registration = {
    attach: function (context, settings) {

      //Only on add form
      /*
      @todo remove old code.
      $('#edit-position').multiselect({
        includeSelectAllOption: true,
        selectAllText: ' Sélectionner tout',
        nonSelectedText: 'Aucun sélectionné',
        allSelectedText: 'Tous sélectionnés',
        enableFiltering: true,
        filterPlaceholder: 'Chercher',
      });

      //Global for add and remove form
      $('#edit-add-users, #edit-remove-users').multiselect({
        includeSelectAllOption: true,
        selectAllText: ' Sélectionner tout',
        nonSelectedText: 'Aucun sélectionné',
        allSelectedText: 'Tous sélectionnés',
        enableFiltering: true,
        filterPlaceholder: 'Chercher'
      });
      */
    }
  };

  /*
  // @todo : remove old code.
  Drupal.ajax.prototype.commands.afterAjaxCallbackExample = function(ajax, response, status) {
    //auto open users dropwdown
    $('#register_many_users button.multiselect').trigger( "click" );

    var $select = $("#register_many_users");

    //Show musicians, only if they are not already hide by the search input
    for (var musician_id in response.musicians_with_position){
      if (response.musicians_with_position.hasOwnProperty(musician_id)) {
        var $li_parent = $select.find('input[value="' + musician_id + '"]').parents('li');
        if (!$li_parent.hasClass("multiselect-filter-hidden")) {
          $select.find('input[value="' + musician_id + '"]').parents('li').addClass('show-'+musician_id).show();
        }
      }
    }

    //Hide unwated musicians
    for (var musician_id in response.musicians_to_hide){
      if (response.musicians_to_hide.hasOwnProperty(musician_id)) {
        $select.find('input[value="' + musician_id + '"]').parents('li').hide();
      }
    }
  };
  */

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