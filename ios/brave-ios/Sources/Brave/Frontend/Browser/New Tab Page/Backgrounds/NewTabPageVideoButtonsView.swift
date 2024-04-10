// Copyright 2024 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

import BraveCore
import BraveUI
import DesignSystem
import Preferences
import Shared
import SnapKit
import UIKit

/// The foreground view of the New Tab Page video player. It contains the cancel
/// button and handles user tap gestures to play/pause the video.
class NewTabPageVideoButtonsView: UIView {
  var tappedVideoBackground: (() -> Bool)?
  var tappedCancelButton: (() -> Void)?

  private let playPauseButtonImage = BluredImageView().then {
    $0.alpha = 0
  }

  private let cancelButton = CancelButton()

  init() {
    super.init(frame: .zero)

    backgroundColor = .clear

    addSubview(cancelButton)
    addSubview(playPauseButtonImage)

    let tapGesture = UITapGestureRecognizer(
      target: self,
      action: #selector(self.videoBackgroundTapped(sender:))
    )
    tapGesture.numberOfTapsRequired = 1
    addGestureRecognizer(tapGesture)

    cancelButton.snp.makeConstraints {
      $0.top.equalTo(self.safeAreaLayoutGuide.snp.top).offset(20)
      $0.right.equalTo(self.safeAreaLayoutGuide.snp.right).offset(-20)
    }
    playPauseButtonImage.snp.makeConstraints {
      $0.centerX.equalToSuperview()
      $0.centerY.equalToSuperview().offset(20)
    }
  }

  override func layoutSubviews() {
    super.layoutSubviews()

    cancelButton.snp.remakeConstraints {
      $0.top.equalTo(self.safeAreaLayoutGuide.snp.top).offset(20)
      $0.right.equalTo(self.safeAreaLayoutGuide.snp.right).offset(-20)
    }
  }

  private func tappedVideoCancelButton() {
    tappedCancelButton?()
  }

  @objc private func videoBackgroundTapped(sender: UITapGestureRecognizer) {
    let location = sender.location(in: self)
    if let view = super.hitTest(location, with: nil), view == cancelButton {
      tappedVideoCancelButton()
      return
    }

    guard let playStarted = tappedVideoBackground?() else {
      return
    }

    if playStarted {
      playPauseButtonImage.setImage(imageName: "leo.play.circle")
      showAndFadeOutImage(imageView: playPauseButtonImage)
    } else {
      playPauseButtonImage.setImage(imageName: "leo.pause.circle")
      showAndFadeOutImage(imageView: playPauseButtonImage)
    }
  }

  private func showAndFadeOutImage(imageView: UIView) {
    imageView.alpha = 0
    UIView.animate(
      withDuration: 0.1,
      animations: {
        imageView.alpha = 1
      },
      completion: { _ in
        UIView.animate(
          withDuration: 0.3,
          delay: 0.5,
          animations: {
            imageView.alpha = 0
          }
        )
      }
    )
  }

  @available(*, unavailable)
  required init(coder: NSCoder) {
    fatalError()
  }
}

extension NewTabPageVideoButtonsView {
  private class CancelButton: SpringButton {
    let imageView = UIImageView(
      image: UIImage(braveSystemNamed: "leo.close", compatibleWith: nil)!
    ).then {
      $0.tintColor = .white
      $0.contentMode = .scaleAspectFit
    }

    private let backgroundView = UIVisualEffectView(
      effect: UIBlurEffect(style: .systemThinMaterialDark)
    ).then {
      $0.clipsToBounds = true
      $0.isUserInteractionEnabled = false
    }

    override init(frame: CGRect) {
      super.init(frame: frame)

      clipsToBounds = true

      addSubview(backgroundView)

      backgroundView.contentView.addSubview(imageView)

      backgroundView.snp.makeConstraints {
        $0.edges.equalToSuperview()
      }
      imageView.snp.makeConstraints {
        $0.width.equalTo(16)
        $0.height.equalTo(16)
        $0.edges.equalToSuperview().inset(UIEdgeInsets(equalInset: 4))
      }
    }

    override func layoutSubviews() {
      super.layoutSubviews()

      layer.cornerRadius = bounds.height / 2.0
    }
  }

  private class BluredImageView: UIView {
    private let backgroundView = UIVisualEffectView(
      effect: UIBlurEffect(style: .systemUltraThinMaterialDark)
    ).then {
      $0.clipsToBounds = true
      $0.isUserInteractionEnabled = false
    }
    private let imageView = UIImageView().then {
      $0.tintColor = .white
      $0.contentMode = .scaleAspectFit
    }

    init() {
      super.init(frame: .zero)

      clipsToBounds = true

      addSubview(backgroundView)

      backgroundView.contentView.addSubview(imageView)

      backgroundView.snp.makeConstraints {
        $0.edges.equalToSuperview()
      }
      imageView.snp.makeConstraints {
        $0.width.equalTo(40)
        $0.height.equalTo(40)
        $0.edges.equalToSuperview().inset(UIEdgeInsets(equalInset: 10))
      }
    }

    override func layoutSubviews() {
      super.layoutSubviews()
      layer.cornerRadius = bounds.height / 2.0
    }

    func setImage(imageName: String) {
      imageView.image = UIImage(braveSystemNamed: imageName, compatibleWith: nil)!
    }

    @available(*, unavailable)
    required init(coder: NSCoder) {
      fatalError()
    }
  }
}
