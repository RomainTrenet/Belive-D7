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
    // Temporary desactivated, Auto open users dropwdown.
    // @todo.
    // $('#register_many_users button.multiselect').trigger( "click" );

    console.log(response);

    var $select = $("#register_many_users");

    // Show artists, only if they are not already hide by the search input
    for (var artist_id in response.artists_with_position){
      if (response.artists_with_position.hasOwnProperty(artist_id)) {

        //var $li_parent = $select.find('input[value="' + artist_id + '"]').parents('li');
        var $li_parent = $select.find('input[value="' + artist_id + '"]').parents('li');
        console.log(artist_id);
        console.log($li_parent);
        if (!$li_parent.hasClass("multiselect-filter-hidden")) {
          $select.find('input[value="' + artist_id + '"]').parents('li').addClass('show-'+artist_id).show();
        }
      }
    }

    //Hide unwated artists
    for (var artist_id in response.artists_to_hide){
      if (response.artists_to_hide.hasOwnProperty(artist_id)) {
        $select.find('input[value="' + artist_id + '"]').parents('li').hide();
      }
    }
  };

})(jQuery);