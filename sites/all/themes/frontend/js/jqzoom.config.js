Drupal.behaviors.jqzoomBehavior = function(context) {	

var options = {
                         zoomWidth: 300,
                         zoomHeight: 300,
                         zoomType:'reverse',
						 showEffect:'show',
                         hideEffect:'fadeout',
                         fadeoutSpeed: 'fast',
						 preloadText: '',
                      }

            $("#zoom-link").jqzoom(options);

};

/*

Название настройки               По умолчанию                Описание

zoomType                         'standard'                        Тип линзы, может быть также  'reverse'.     
zoomWidth                        200                                  Ширина поп-апа с увеличенным изображением.
zoomHeight                       200                                  Высота поп-апа с увеличенным изображением.
xOffset                          10                                    Отступ поп-апа с увеличенным изображением от маленькой картинки по горизонтали.Позитивное значение для позиции right/left и позитивное/негативное для позиции top/bottom.
yOffset                          0                                      Отступ поп-апа с увеличенным изображением. Всегда позитивное значение для позиции 'right/left', всегда позитивное для позиции 'top/bottom'.
position                         'right'                                Позиция поп-апа. Допустимые значения:'right' ,'left' ,'top' ,'bottom'
lens                             true                                  Если установлено в false, линза не будет показана.
imageOpacity                     0.2                                    Прозрачность наложения, если  'zoomType' установлено в 'reverse'.
title                            true                                  Надпись над изображением (берётся из тега title).
showEffect                       'show'                              Эффект показа поп-апа. Доступно: 'show' ,'fadein'.
hideEffect                       'hide'                               Эффект закрытия поп-апа. Доступно: 'hide' ,'fadeout'.
fadeinSpeed                      'fast'                                Скорость исчезания, если showEffect установлено в 'fadein'. Доступно: 'fast','slow','medium')
fadeoutSpeed                     'slow'                               Скорость появления поп-апа, если hideEffect установлена в  'fadeout'. Доступно: 'fast','slow','medium')
showPreload                      true                                 Показ индикатора загрузки. Доступно: 'true','false')
preloadText                      'Loading zoom'                Текст индикатора загрузки.
preloadPosition                  'center'                            Позиция индикатора загрузки.

*/


