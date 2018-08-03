(function($) {
	Drupal.behaviors.multiple_select = {
		attach: function (context, settings) {
      //$('.multiple-select').multipleSelect();
      $('select.multiple-select').multipleSelect({
        width: '100%',
        filter: true,
        //multiple: true,
				placeholder: 'TRUC'
        /*onOpen: function() {
          //$eventResult.text('Select opened!');
        },*/
			});
		}
	};
})(jQuery);