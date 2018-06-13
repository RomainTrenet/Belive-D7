(function($) {

  Drupal.behaviors.band_booking_registration = {
    attach: function (context, settings) {

      //Only on add form
      $('#edit-position').multiselect({
        includeSelectAllOption: true,
        selectAllText: ' Sélectionner tout',
        nonSelectedText: 'Aucun sélectionné',
        allSelectedText: 'Tous sélectionnés',
        enableFiltering: true,
        filterPlaceholder: 'Chercher',
      });

      //Global for add and remove form
      $('#edit-users').multiselect({
        includeSelectAllOption: true,
        selectAllText: ' Sélectionner tout',
        nonSelectedText: 'Aucun sélectionné',
        allSelectedText: 'Tous sélectionnés',
        enableFiltering: true,
        filterPlaceholder: 'Chercher'
      });
    }
  };

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

})(jQuery);